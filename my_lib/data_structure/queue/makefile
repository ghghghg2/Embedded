SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)


.PHONY: all clean

all: test

-include $(DEPS)   #註釋:'-'號的作用：加載錯誤時，會繼續執行 make，主要是考慮到首次 make 時，目錄中若不存在 '*.d' 文件時，加載便會產生錯誤而停止 make 的執行

%.o:%.c
		gcc -c -g -Wall $< -o $@ -MD -MF $*.d -MP

test: $(OBJS)
		gcc $^ -o $@   #註釋:$^:表示所有的依賴文件 $@:表示目標文件
		rm -f *.d *.o	# remove all *.o and *.d files

clean:
		rm -f *.d *.o test

# - $* 表示目標模式中 '%' 及其之前的部分.如果目標是 'dir/a.foo.b',並且目標的模式爲 'a.%.b',那麼 '$*' 的值就是 'dir/a.foo'. 
# - $@ : 表示一個規則中的目標.當規則中有多個目標時,$@ 所指的是其中任何造成規則的命令運行的目標
# - $^ : 表示規則中的所有依賴項
# - $< : 表示規則中的第一個依賴項