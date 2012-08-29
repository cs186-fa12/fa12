require 'test/unit'
require './test/diff_files'
REFERENCE_FILE_PATH = "/home/ff/cs186/sp12/hw1"

class FullTest < Test::Unit::TestCase
  def test_full
    diff_files("enron_with_categories")
  end
end
