FROM	ubuntu

RUN	apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install build-essential git vim valgrind -y

RUN git clone https://github.com/42Paris/minilibx-linux mlx && \
	apt-get install libxext-dev -y && \
	apt-get install libbsd-dev -y

RUN	cd mlx; ./configure && \
	cp libmlx.a /usr/local/lib/ && \
	cp mlx.h /usr/local/include/