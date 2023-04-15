CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: feribot nostory sushi semnale badgpt

run-p1:
	./feribot
run-p2:
	./nostory
run-p3:
	./sushi
run-p4:
	./semnale
run-p5:
	./badgpt

feribot: feribot.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
nostory: nostory.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
sushi: sushi.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
semnale: semnale.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
badgpt: badgpt.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f feribot nostory sushi semnale badgpt
