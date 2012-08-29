require 'test/unit'
require './test/diff_files'
REFERENCE_FILE_PATH = "/home/ff/cs186/fa12/hw1"

class FullTest < Test::Unit::TestCase
  def test_full
    diff_files("enron_full")
  end
end
