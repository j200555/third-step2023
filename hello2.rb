puts "笑介くんのクラス20人のテストの点数は、理科が\n"
score1=[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
score2=[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23,65, 84, 64, 27, 86, 84]
#ave1=score1.sum.to_f / score1.size.to_f
#ave2=score2.sum.to_f / score2.size.to_f
class Array
  # 要素をto_iした値の平均を算出する
  def avg
    inject(0.0){|r,i| r+=i.to_i }/size
  end
  def variance
    a = avg
    inject(0.0){|r,i| r+=(i.to_i-a)**2 }/size
  end  
# 要素をto_iした値の標準偏差を算出する
  def standard_deviation
    Math.sqrt(variance)
  end
end
def dev(arr_x)
#標準偏差stdを求める。
    avg = arr_x.sum / arr_x.length
    arr1 = arr_x.map{|x| (x - avg) ** 2}
    std = Math.sqrt(arr1.sum / arr_x.length)
#配列の要素を偏差値に変換して返す。
    return arr_x.map{|x| ((x - avg) * 10 / std + 50).round(2)}
end 
score1.each do |element|
	print  element
	print " "
end

print "\n英語が\n"
score2.each do |element|
	print element
	print " "
end
print "\n でした。\n"
print "理科平均:"
puts score1.avg
print "英語平均:"
puts score2.avg
print "理科標準偏差:"
puts score1.standard_deviation
print "英語標準偏差:"
puts score2.standard_deviation
print "理科合計点:"
puts score1.sum
print "英語合計点:"
puts score2.sum
print "理科偏差値:"
puts dev(score1)
print "英語偏差値:"
puts dev(score2)
print "理科(高い順):"
puts score1.sort.reverse
print "英語(高い順):"
puts score2.sort.reverse 



