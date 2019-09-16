cmd = {}
cmd.str = ""
local config = require("config")

function cmd:clone(path,name)
    if name then
        return self:add(string.format([[git clone --recursive --depth=1 %s %s]],path,name))
    end
    return self:add(string.format([[git clone --recursive --depth=1 %s]],path))
end

function cmd:cd(path)
    return self:add(string.format([[cd %s]],path))
end

function cmd:mkdir(name)
    return self:add(string.format([[mkdir %s]],name))
end

function cmd:msbuild(path)
    return self:add(string.format([["%sMSBuild" %s /t:Rebuild /p:Configuration=Release /p:Platform=x86]],config.msbuild,path))
end

function cmd:javac(path)
    return self:add(string.format([["%sjavac" %s]],config.javac,path))
end

function cmd:gradlew()
    return self:add(string.format([["gradlew.bat" clean && "gradlew.bat" build]]))
end

function cmd:runExe(path,file)
    return self:add(string.format([[%s > %s]],path,file))
end

function cmd:runClass(path,file)
    return self:add(string.format([[java %s > %s]],path,file))
end

function cmd:runJar(path,file)
    return self:add(string.format([[java -Dfile.encode=UTF-8 -jar %s > %s]],path,file))
end

function cmd:runPy(path,file)
    return self:add(string.format([[python %s > %s]],path,file))
end

function cmd:copy(old,new)
    return self:add(string.format([[copy "%s" "%s"]],old,new))
end

function cmd:add(str1)
    if self.str~="" then
        self.str = string.format([[%s && %s]],self.str,str1)
    else
        self.str = str1
    end
    return self;
end

function cmd:run()
    print(self.str)
    os.execute(self.str)
    self.str=""
    return self
end

return cmd