output = File.new("code.txt", "w")
input = File.new("words.txt")
input.each do |line|
    output.puts "   {{"
    output.puts "        // #{line}"
    
    line.split(",").each do |word|
        unless word == "\n"
            output.print "        { "
            for i in (0..word.length - 3)  
                output.print "PAIR(#{word[i]},#{word[i]}), "
            end
            output.print "PAIR(#{word[-2,2]},#{word[-2,2]}), "
            output.print " -1 },\n"
        end
    end
    output.puts "   }},"
end
input.close
output.close
