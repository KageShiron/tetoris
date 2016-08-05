ary = []
File.open(ARGV[0],"rb") do |file|
    file.each_line do |l|
        next if l.start_with?("#")
        l.gsub(/[^0-9]/,"").chars{|ch| p ch ; ary.push(ch.to_i) }
    end
end
p ary
File.open(ARGV[1],"wb") do |file|
    file.write([ary.size,0,0,0].pack("i*"))
    file.write(ary.pack("C*"))
end
