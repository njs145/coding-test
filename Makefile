# 컴파일할 소스 디렉토리 (기본값: src)
DIR ?= src

# 빌드 아웃풋 디렉토리
BUILD_DIR := build

# 컴파일러 설정
CXX := /usr/bin/aarch64-linux-gnu-g++
CXXFLAGS := -Wall -O2 -std=c++17

# 소스 파일과 대응하는 오브젝트 파일 (build/에 저장)
SRCS := $(wildcard $(DIR)/*.cpp)
OBJS := $(patsubst $(DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# 타겟 바이너리 경로
TARGET := $(BUILD_DIR)/app

# 기본 타겟
all: $(TARGET)

# app 링크
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# build 디렉토리 안에 .o 파일 만들기
$(BUILD_DIR)/%.o: $(DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 정리
clean:
	rm -rf $(BUILD_DIR)
