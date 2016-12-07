require 'rubygems'
require 'inline'
require 'benchmark'
require 'pry'

class Example
  inline do |builder|
    builder.c "
     long long factorial(int max) {
       int i=max;
       long long result = 1;
       while (i >= 2) { result *= i--; }
       return result;
     }
    "
  end
end

class Integer
  def fact
    (1..self).reduce(:*) || 1
  end
end

t = Example.new
puts t.factorial(60)
#binding.pry
time = Benchmark.measure do
  100000.times {t.factorial(20)}
end
puts "Inline C: ".concat(time.to_s)
time = Benchmark.measure do
  100000.times {20.fact}
end
puts "Ruby: ".concat(time.to_s)
