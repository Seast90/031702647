local i = 1
function get_dir_file(dirpath,func)
    os.execute('dir "' .. dirpath .. '" /b  > '..i..'.temp')
    io.input(i..".temp")
    i=i+1
    for line in io.lines() do
         if line then
            func(line) 
         end
    end
    io.close()
end
function string.starts(String,Start)
    return string.sub(String,1,string.len(Start))==Start
 end
 
 function string.ends(String,End)
    return End=='' or string.sub(String,-string.len(End))==End
 end

 function string.rmEnd(String,End)
   return string.sub(String,1,-End)
end

 function table.same(a,b)
   if a==nil then
      return false
   end
   if a~=nil then
      for k,v in pairs(a) do  
         if type(v)=="table" then
            if table.same(b[k],v)==false then
               return false            
            end 
         else
            if b[k]~=v then
               return false
            end
         end
      end
  end
  return true
 end