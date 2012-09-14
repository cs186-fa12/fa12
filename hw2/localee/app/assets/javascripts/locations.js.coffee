$ ->

  # create map
  if $("#new-location-map-canvas").size() > 0
    mapOptions = {
      center: new google.maps.LatLng(37.8755843, -122.259167),
      zoom: 14,
      mapTypeId: google.maps.MapTypeId.ROADMAP,
      streetViewControl: false,
      draggableCursor: 'crosshair',
      mapTypeControl: false
    }
    map = new google.maps.Map(document.getElementById("new-location-map-canvas"), mapOptions)

    document.getElementById("create_tab_btn").onclick = () ->
      setTimeout(() ->
        google.maps.event.trigger(map, 'resize')
        map.setZoom(map.getZoom())
      , 200)

    # Set default location
    
    if(navigator.geolocation)
      navigator.geolocation.getCurrentPosition((position) ->
        pos = new google.maps.LatLng(position.coords.latitude, position.coords.longitude)
        map.setCenter(pos))
    else
      # Geolocation not supported by browser

    marker = undefined

    # enable/disable create button if fields are not filled out.
    enableCreateLocation = () ->
      text = document.getElementById("location_name").value
      if (marker == undefined || text.length == 0)
        document.getElementById("create_location_btn").setAttribute("disabled", "disabled")
      else
        document.getElementById("create_location_btn").removeAttribute("disabled")

    document.getElementById("location_name").onkeydown = enableCreateLocation
    document.getElementById("location_name").onkeypress = enableCreateLocation
    document.getElementById("location_name").onkeyup = enableCreateLocation

    # Bind the click event
    google.maps.event.addListener(map, 'click', (e) ->
      pos = e.latLng
      map.getBounds().extend(pos)

      if (marker == undefined)
        markerOptions = {
          position: pos,
          clickable: false,
          map: map
        }
        marker = new google.maps.Marker(markerOptions)
      else
        marker.setPosition(pos)

      # Populate text boxes with values
      $("#location_latitude").val(pos.lat())
      $("#location_longitude").val(pos.lng())

      enableCreateLocation()
    )

  # nearby map
  if $("#new-location-map-canvas").size() > 0
    mapOptions = {
      center: new google.maps.LatLng(37.8755843, -122.259167),
      zoom: 14,
      mapTypeId: google.maps.MapTypeId.ROADMAP,
      streetViewControl: false,
      mapTypeControl: false
    }
    nearbyMap = new google.maps.Map(document.getElementById("nearby-locations-map-canvas"), mapOptions)

    if(navigator.geolocation)
      navigator.geolocation.getCurrentPosition((position) ->
        pos = new google.maps.LatLng(position.coords.latitude, position.coords.longitude)
        nearbyMap.setCenter(pos))

    idleTimeout = 0

    markers = new Array()

    listeners = new Array()

    infoWindow = new google.maps.InfoWindow({
      content: ""
    })
    infoMarker = null

    # has to be a separate function for consecutive addListeners to work
    addListener = (m, id) ->
      google.maps.event.addListener(m, 'click', () ->
        if (infoMarker == m)
          infoWindow.close()
          infoMarker = null
        else
          # TODO: add follow/unfollow button in content
          infoWindow.setContent("<strong><a href=\"/location/" + id + "\">" + m.title + "</a></strong>")
          infoWindow.open(nearbyMap, m)
          infoMarker = m
      )

    handleLocationResponse = (data) ->
      markerNames = for m in markers
        m.getPosition().lat() + "," + m.getPosition().lng()
      newNames = for m in data
        m.latitude + "," + m.longitude
      if (markerNames != undefined && newNames != undefined)
        markerNames.sort()
        newNames.sort()
        if (markerNames.join() == newNames.join())
          # No need to update anything.
          return

      google.maps.event.removeListener(l) for l in listeners
      m.setMap(null) for m in markers
      markers.length = 0

      markers = for l in data
        pos = new google.maps.LatLng(l.latitude, l.longitude)
        markerOptions = {
          title: l.name,
          position: pos,
          map: nearbyMap
        }
        new google.maps.Marker(markerOptions)

      listeners = for m, i in markers
        addListener(m, data[i].id)

      # update list of locations.
      dataDivs = for l in data
        follows = if (l.follows)
          "<a href=\"/locations/" + l.id + "/unfollow\" class=\"btn btn-small\" data-method=\"post\" rel=\"nofollow\">Unfollow</a>"
        else
          "<a href=\"/locations/" + l.id + "/follow\" class=\"btn btn-small\" data-method=\"post\" rel=\"nofollow\">Follow</a>"
        "<div class='well'><strong><a href=\"/location/" + l.id + "\">" + l.name + "</a></strong>" + "<div class='pull-right'>" + follows + "</div>" + "</div>"
      $("#nearby-locations-list").html(dataDivs)

    # when the map is clicked, clear info window.
    google.maps.event.addListener(nearbyMap, 'click', () ->
      infoWindow.close()
      infoMarker = null
    )

    google.maps.event.addListener(nearbyMap, 'idle', () ->
      clearTimeout(idleTimeout)
      idleTimeout = setTimeout(() ->
        # send ajax with location parameters.
        bounds = nearbyMap.getBounds()
        ne = bounds.getNorthEast()
        sw = bounds.getSouthWest()
        $.post("/nearby_locations", {nelat: "" + ne.lat(), nelng: "" + ne.lng(), swlat: "" + sw.lat(), swlng: "" + sw.lng()}, handleLocationResponse)
      , 250)
    )
