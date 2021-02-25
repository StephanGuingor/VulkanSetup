workspace "VulkanSetup"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include directories relative to root (sln)
    IncludeDir  = {}
    IncludeDir["GLFW"] = "VulkanS/vendor/GLFW/include"
    
    -- Include premake
    group "Dependencies"
        include "VulkanS/vendor/GLFW"
    group ""
    
    project "VulkanS"
        location "VulkanS"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"
    
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
        pchheader "vkpch.h"
        pchsource "VulkanS/src/vkpch.cpp"
    
        files 
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
  
        }
    
        defines 
        {
         "_CRT_SECURE_NO_WARNINGS"
        }
    
        includedirs 
        {
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{IncludeDir.GLFW}",
            "%{prj.name}/vendor/vulkansdk/include"
        }
    
        libdirs 
        {
            "%{prj.name}/vendor/vulkansdk/Lib"
        }
        links
        {
            "GLFW",
            "vulkan-1"
        }
    
        filter "system:windows"
           systemversion "latest"
    
            defines
            {
                "PS_PLATFORM_WINDOW",
             --   "GLFW_INCLUDE_NONE"
            }
    
    
        filter "configurations:Debug"
            defines 
            {
                "PS_DEBUG",
                "PS_ENABLE_ASSERTS"
            }
            symbols "On"
            runtime "Debug"
            
        filter "configurations:Release"
            defines "PS_RELEASE"
            optimize  "On"
            runtime "Release"
    
        filter "configurations:Dist"
            defines "PS_DIST"
            optimize  "On"
            runtime "Release"
    
    