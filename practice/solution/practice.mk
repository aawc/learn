##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=practice
ConfigurationName      :=Debug
WorkspacePath          := "E:\Varun\GitHub\learn\practice\solution"
ProjectPath            := "E:\Varun\GitHub\learn\practice\solution"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=varunkh
Date                   :=5/3/2013
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
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
ObjectsFileList        :="practice.txt"
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
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\Program Files (x86)\CodeLite\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_BinaryTree$(ObjectSuffix) $(IntermediateDirectory)/src_BinaryTreeNode$(ObjectSuffix) $(IntermediateDirectory)/src_InsertSort$(ObjectSuffix) $(IntermediateDirectory)/src_InsertSortSTL$(ObjectSuffix) $(IntermediateDirectory)/src_LinkedListLoop$(ObjectSuffix) $(IntermediateDirectory)/src_main$(ObjectSuffix) $(IntermediateDirectory)/src_MergeSort$(ObjectSuffix) $(IntermediateDirectory)/src_MergeSortSTL$(ObjectSuffix) $(IntermediateDirectory)/src_QuickSortSTL$(ObjectSuffix) $(IntermediateDirectory)/src_ThreadedBinaryTree$(ObjectSuffix) \
	$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(ObjectSuffix) $(IntermediateDirectory)/src_LinkedList$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_BinaryTree$(ObjectSuffix): ../src/BinaryTree.cpp $(IntermediateDirectory)/src_BinaryTree$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/BinaryTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BinaryTree$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BinaryTree$(DependSuffix): ../src/BinaryTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_BinaryTree$(ObjectSuffix) -MF$(IntermediateDirectory)/src_BinaryTree$(DependSuffix) -MM "../src/BinaryTree.cpp"

$(IntermediateDirectory)/src_BinaryTree$(PreprocessSuffix): ../src/BinaryTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BinaryTree$(PreprocessSuffix) "../src/BinaryTree.cpp"

$(IntermediateDirectory)/src_BinaryTreeNode$(ObjectSuffix): ../src/BinaryTreeNode.cpp $(IntermediateDirectory)/src_BinaryTreeNode$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/BinaryTreeNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_BinaryTreeNode$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_BinaryTreeNode$(DependSuffix): ../src/BinaryTreeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_BinaryTreeNode$(ObjectSuffix) -MF$(IntermediateDirectory)/src_BinaryTreeNode$(DependSuffix) -MM "../src/BinaryTreeNode.cpp"

$(IntermediateDirectory)/src_BinaryTreeNode$(PreprocessSuffix): ../src/BinaryTreeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_BinaryTreeNode$(PreprocessSuffix) "../src/BinaryTreeNode.cpp"

$(IntermediateDirectory)/src_InsertSort$(ObjectSuffix): ../src/InsertSort.cpp $(IntermediateDirectory)/src_InsertSort$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/InsertSort.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_InsertSort$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_InsertSort$(DependSuffix): ../src/InsertSort.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_InsertSort$(ObjectSuffix) -MF$(IntermediateDirectory)/src_InsertSort$(DependSuffix) -MM "../src/InsertSort.cpp"

$(IntermediateDirectory)/src_InsertSort$(PreprocessSuffix): ../src/InsertSort.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_InsertSort$(PreprocessSuffix) "../src/InsertSort.cpp"

$(IntermediateDirectory)/src_InsertSortSTL$(ObjectSuffix): ../src/InsertSortSTL.cpp $(IntermediateDirectory)/src_InsertSortSTL$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/InsertSortSTL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_InsertSortSTL$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_InsertSortSTL$(DependSuffix): ../src/InsertSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_InsertSortSTL$(ObjectSuffix) -MF$(IntermediateDirectory)/src_InsertSortSTL$(DependSuffix) -MM "../src/InsertSortSTL.cpp"

$(IntermediateDirectory)/src_InsertSortSTL$(PreprocessSuffix): ../src/InsertSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_InsertSortSTL$(PreprocessSuffix) "../src/InsertSortSTL.cpp"

$(IntermediateDirectory)/src_LinkedListLoop$(ObjectSuffix): ../src/LinkedListLoop.cpp $(IntermediateDirectory)/src_LinkedListLoop$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/LinkedListLoop.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LinkedListLoop$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LinkedListLoop$(DependSuffix): ../src/LinkedListLoop.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LinkedListLoop$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LinkedListLoop$(DependSuffix) -MM "../src/LinkedListLoop.cpp"

$(IntermediateDirectory)/src_LinkedListLoop$(PreprocessSuffix): ../src/LinkedListLoop.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LinkedListLoop$(PreprocessSuffix) "../src/LinkedListLoop.cpp"

$(IntermediateDirectory)/src_main$(ObjectSuffix): ../src/main.cpp $(IntermediateDirectory)/src_main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main$(DependSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main$(DependSuffix) -MM "../src/main.cpp"

$(IntermediateDirectory)/src_main$(PreprocessSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main$(PreprocessSuffix) "../src/main.cpp"

$(IntermediateDirectory)/src_MergeSort$(ObjectSuffix): ../src/MergeSort.cpp $(IntermediateDirectory)/src_MergeSort$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/MergeSort.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MergeSort$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MergeSort$(DependSuffix): ../src/MergeSort.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MergeSort$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MergeSort$(DependSuffix) -MM "../src/MergeSort.cpp"

$(IntermediateDirectory)/src_MergeSort$(PreprocessSuffix): ../src/MergeSort.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MergeSort$(PreprocessSuffix) "../src/MergeSort.cpp"

$(IntermediateDirectory)/src_MergeSortSTL$(ObjectSuffix): ../src/MergeSortSTL.cpp $(IntermediateDirectory)/src_MergeSortSTL$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/MergeSortSTL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MergeSortSTL$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MergeSortSTL$(DependSuffix): ../src/MergeSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MergeSortSTL$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MergeSortSTL$(DependSuffix) -MM "../src/MergeSortSTL.cpp"

$(IntermediateDirectory)/src_MergeSortSTL$(PreprocessSuffix): ../src/MergeSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MergeSortSTL$(PreprocessSuffix) "../src/MergeSortSTL.cpp"

$(IntermediateDirectory)/src_QuickSortSTL$(ObjectSuffix): ../src/QuickSortSTL.cpp $(IntermediateDirectory)/src_QuickSortSTL$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/QuickSortSTL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_QuickSortSTL$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_QuickSortSTL$(DependSuffix): ../src/QuickSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_QuickSortSTL$(ObjectSuffix) -MF$(IntermediateDirectory)/src_QuickSortSTL$(DependSuffix) -MM "../src/QuickSortSTL.cpp"

$(IntermediateDirectory)/src_QuickSortSTL$(PreprocessSuffix): ../src/QuickSortSTL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_QuickSortSTL$(PreprocessSuffix) "../src/QuickSortSTL.cpp"

$(IntermediateDirectory)/src_ThreadedBinaryTree$(ObjectSuffix): ../src/ThreadedBinaryTree.cpp $(IntermediateDirectory)/src_ThreadedBinaryTree$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/ThreadedBinaryTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ThreadedBinaryTree$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ThreadedBinaryTree$(DependSuffix): ../src/ThreadedBinaryTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ThreadedBinaryTree$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ThreadedBinaryTree$(DependSuffix) -MM "../src/ThreadedBinaryTree.cpp"

$(IntermediateDirectory)/src_ThreadedBinaryTree$(PreprocessSuffix): ../src/ThreadedBinaryTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ThreadedBinaryTree$(PreprocessSuffix) "../src/ThreadedBinaryTree.cpp"

$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(ObjectSuffix): ../src/ThreadedBinaryTreeNode.cpp $(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/ThreadedBinaryTreeNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(DependSuffix): ../src/ThreadedBinaryTreeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(DependSuffix) -MM "../src/ThreadedBinaryTreeNode.cpp"

$(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(PreprocessSuffix): ../src/ThreadedBinaryTreeNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(PreprocessSuffix) "../src/ThreadedBinaryTreeNode.cpp"

$(IntermediateDirectory)/src_LinkedList$(ObjectSuffix): ../src/LinkedList.cpp $(IntermediateDirectory)/src_LinkedList$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/practice/src/LinkedList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LinkedList$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LinkedList$(DependSuffix): ../src/LinkedList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LinkedList$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LinkedList$(DependSuffix) -MM "../src/LinkedList.cpp"

$(IntermediateDirectory)/src_LinkedList$(PreprocessSuffix): ../src/LinkedList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LinkedList$(PreprocessSuffix) "../src/LinkedList.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_BinaryTree$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_BinaryTree$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_BinaryTree$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_BinaryTreeNode$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_BinaryTreeNode$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_BinaryTreeNode$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSort$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSort$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSort$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSortSTL$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSortSTL$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_InsertSortSTL$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedListLoop$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedListLoop$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedListLoop$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSort$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSort$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSort$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSortSTL$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSortSTL$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_MergeSortSTL$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_QuickSortSTL$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_QuickSortSTL$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_QuickSortSTL$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTree$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTree$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTree$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ThreadedBinaryTreeNode$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedList$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedList$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_LinkedList$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/practice"


