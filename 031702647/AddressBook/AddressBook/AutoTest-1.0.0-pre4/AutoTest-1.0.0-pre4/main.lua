local util = require("util")
local cmd = require("cmds")
-- local repo = require("repo")
local json = require("json")

require("help")

local function err_handle(x)
    print("error:" .. x)
end


cmd:mkdir("test")
cmd:mkdir("mark")
cmd:mkdir("out")
cmd:cd("test")
cmd:mkdir("git")
cmd:mkdir("ans")
cmd:mkdir("exe")
cmd:run()

local f = io.open(string.format("repo.json",str),"r")
local ans = f:read('*all')
f:close()
local f, gits = xpcall(function()return json.decode(ans)end, err_handle)
if gits==nil then
    error("error in repo.json")
end

for k,v in pairs(gits) do
    cmd:cd("test")
    cmd:cd("git")
    cmd:clone(v,k)
    cmd:run()
end

get_dir_file("test\\git",function (str1)
    get_dir_file(string.format("test\\git\\%s",str1),function (str)
        if string.ends(str,".sln") then
            cmd:cd(string.format("test\\git\\%s",str1))
            cmd:msbuild(str)
            cmd:copy(".\\Release\\addressbook.exe",string.format([[..\..\exe\%s.exe]],str1 ))
        end
        if str=="gradlew.bat" then
            cmd:cd(string.format("test\\git\\%s",str1))
            cmd:gradlew()
            cmd:copy("build\\libs\\addressbook.jar",string.format([[..\..\exe\%s.jar]],str1 ))
        end
        if str=="addressbook.py" then
            cmd:cd(string.format("test\\git\\%s",str1))
            cmd:copy("addressbook.py",string.format([[..\..\exe\%s.py]],str1 ))
        end
        cmd:run()
    end)
end)


get_dir_file("test\\exe",function (str)
    cmd:cd("out")
    if string.ends(str,".py") then
        cmd:mkdir(string.rmEnd(str,4))
    else
        cmd:mkdir(string.rmEnd(str,5))
    end
    cmd:run()
    get_dir_file("in",function (in0)
        cmd:cd("test")
        cmd:cd("exe")
        if string.ends(str,".exe") then
           cmd:runExe(str..[[ ..\..\in\]]..in0..[[ ..\..\out\]]..string.rmEnd(str,5).."\\"..in0,string.format([[..\ans\%s.txt]],(str..in0)))
        end
        if string.ends(str,".jar") then
            cmd:runJar(str..[[ ..\..\in\]]..in0..[[ ..\..\out\]]..string.rmEnd(str,5).."\\"..in0,string.format([[..\ans\%s.txt]],(str..in0)))
        end
        if string.ends(str,".py") then
            cmd:runPy(str..[[ ..\..\in\]]..in0..[[ ..\..\out\]]..string.rmEnd(str,5).."\\"..in0,string.format([[..\ans\%s.txt]],(str..in0)))
        end
        cmd:run()
    end)
end)

get_dir_file("out",function (str0)
    local sum = 0
    get_dir_file("out\\"..str0,function (str)
        local f = io.open(string.format([[out\%s\%s]],str0,str),"r")
        local content = f:read('*all')
        f:close()
        local f = io.open(string.format([[truth\%s]],str),"r")
        local ans = f:read('*all')
        f:close()
        local f, content = xpcall(function()return json.decode(content)end, err_handle)
        local f, ans = xpcall(function()return json.decode(ans)end, err_handle)
        if content~=nil and ans~=nil then
           if (table.same(content,ans)) then
               sum=sum+1
           end
        end
        local f = io.open(string.format([[mark\%s]],str0),"w")
        f:write(sum)
        f:flush()
        f:close(file)
        cmd:run()
    end)
end)
