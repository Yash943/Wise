workspace "Wise"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir ="%{cfg.buildcfg}".."-".."%{cfg.system}".."-".."%{cfg.architecture}"
-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Wise/vendor/GLFW/include"
IncludeDir["Glad"] = "Wise/vendor/Glad/include"
IncludeDir["ImGui"] = "Wise/vendor/imgui"
IncludeDir["glm"] = "Wise/vendor/glm"

include "Wise/vendor/GLFW"
include "Wise/vendor/Glad"
include "Wise/vendor/imgui"


project "Wise"
	location "Wise"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wspch.h"
	pchsource "Wise/src/wspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"WS_PLATFORM_WINDOWS",
			"WS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WS_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "On"

		
	filter "configurations:Release"
		defines "WS_RELEASE"
		runtime "Release"
		buildoptions "/MDd"
		optimize "On"
		

	filter "configurations:Dist"
		defines "WS_DIST"
		runtime "Release"
		buildoptions "/MDd"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Wise/vendor/spdlog/include",
		"Wise/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Wise"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"WS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "WS_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "On"

		
	filter "configurations:Release"
		defines "WS_RELEASE"
		runtime "Release"
		buildoptions "/MDd"
		optimize "On"
		

	filter "configurations:Dist"
		defines "WS_DIST"
		runtime "Release"
		buildoptions "/MDd"
		optimize "On"