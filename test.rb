require './mytest'
require 'pry'
require 'benchmark'

def fact(num)
  result = 0
  (1..num).each do |n|
    result *= num
  end
end

c_lib = MyTest.new
Benchmark.bmbm do |x|
  x.report("C factorial of 150") { 200000.times { c_lib.factorial(150) } }
  x.report("Ruby factorial of 150") { 200000.times { fact(150) } }
end
