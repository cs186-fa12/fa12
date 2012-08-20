def diff_files(subpath)
  # ensure sane sort orders from UNIX sort
  ENV['LC_ALL'] = 'C'

  # cap virtual memory usage to detect memory hogs
  l = Process.getrlimit(:AS)
  Process.setrlimit(:AS, 100000*1024, l[1])

  # run hw1.sh script and make sure it succeeds
  assert((system "/bin/bash hw1.sh #{REFERENCE_FILE_PATH}/#{subpath}"), "hw1 script did not return happily")

  # uncap virtual memory usage 
  Process.setrlimit(:AS, l[0], l[1])

  # compare each of the resulting csv files with reference versions
  ['mail', 'tokens', 'token_counts', 'state_counts'].each do |fname|
    assert((system "sort #{fname}.csv > #{fname}-sorted.csv"), "sort did not return happily")
    assert_equal('', `diff -q #{fname}-sorted.csv #{REFERENCE_FILE_PATH}/#{subpath}.out/#{fname}-sorted.csv`)
    assert((system "rm #{fname}-sorted.csv"), "rm did not return happily")
  end
end
