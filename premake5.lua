workspace "Bank"
    architecture "x64"
    configurations { "Debug", "Release", "Distribution" }
    startproject "Bank"

    -- Enable multithreaded builds
    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

filter "configurations:Debug"
    defines "DEBUG"
    runtime "Debug"
    symbols "on"

filter "configurations:Release"
    defines "NDEBUG"
    runtime "Release"
    optimize "on"

filter "configurations:Distribution"
    defines {"NDEBUG", "__DIST__"}
    runtime "Release"
    optimize "Speed"  -- Highest speed optimizations
    flags { "LinkTimeOptimization" }  -- Enable link-time optimization
    buildoptions { "/GL", "/Ot" }  -- Favor speed over size (MSVC)

project "Bank"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")
    
    files {
        "src/**.hpp",
        "src/**.cpp"
    }
