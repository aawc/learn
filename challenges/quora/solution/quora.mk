##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=quora
ConfigurationName      :=Debug
WorkspacePath          := "E:\Varun\GitHub\learn\practice\solution"
ProjectPath            := "E:\Varun\GitHub\learn\challenges\quora\solution"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=varunkh
Date                   :=5/5/2013
CodeLitePath           :="D:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="quora.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=D:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main$(ObjectSuffix): ../src/main.cpp $(IntermediateDirectory)/src_main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main$(DependSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main$(DependSuffix) -MM "../src/main.cpp"

$(IntermediateDirectory)/src_main$(PreprocessSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main$(PreprocessSuffix) "../src/main.cpp"

$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix): ../src/01_Nearby.cpp $(IntermediateDirectory)/src_01_Nearby$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/01_Nearby.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_01_Nearby$(DependSuffix): ../src/01_Nearby.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) -MF$(IntermediateDirectory)/src_01_Nearby$(DependSuffix) -MM "../src/01_Nearby.cpp"

$(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix): ../src/01_Nearby.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix) "../src/01_Nearby.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../../practice/solution/.build-debug/quora"


