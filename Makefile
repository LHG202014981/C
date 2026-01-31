# 변수 설정
CC = gcc
TARGET = app
SRC = book.c
COMMIT_MSG = "C 프로젝트 업데이트 ($(shell date +'%Y-%m-%d %H:%M:%S'))"

# 1. 컴파일만 하기 (명령어: make build)
build:
	$(CC) $(SRC) -o $(TARGET)
	@echo "컴파일 완료: $(TARGET).exe"

# 2. 깃허브 업로드만 하기 (명령어: make push)
push:
	git add .
	git commit -m $(COMMIT_MSG)
	git push origin main
	@echo "깃허브 업로드 완료!"

# 3. 컴파일 후 바로 실행 (명령어: make run)
run: build
	./$(TARGET)