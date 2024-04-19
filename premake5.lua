workspace "Wise"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir ="%{cfg.buildcfg}".."-".."%{cfg.system}".."-".."%{cfg.architecture}"

project "Wise"
	location "Wise"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WS_PLATFORM_WINDOWS",
			"WS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WS_DEBUG"
		symbols "On"

		
	filter "configurations:Release"
		defines "WS_RELEASE"
		optimize "On"
		

	filter "configurations:Dist"
		defines "WS_DIST"
		optimize "On"

	filter{"system:windows", "configurations:Release"}
		buildoptions "/MT"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Wise/src"
	}

	links
	{
		"Wise"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WS_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "WS_DEBUG"
		symbols "On"

		
	filter "configurations:Release"
		defines "WS_RELEASE"
		optimize "On"
		

	filter "configurations:Dist"
		defines "WS_DIST"
		optimize "On"

	filter{"system:windows", "configurations:Release"}
		buildoptions "/MT"