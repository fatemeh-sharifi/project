CC=g++ -std=c++20

EXE = sputify.out

all: ${EXE}

${EXE}: main.o request.o response.o strutils.o template_parser.o utilities.o route.o server.o handlers.o Spotify.o User.o Music.o Playlist.o string_functions.o Artist.o Regular_user.o Time.o
	${CC} main.o request.o response.o strutils.o template_parser.o utilities.o route.o server.o handlers.o Spotify.o User.o Music.o Playlist.o string_functions.o Artist.o Regular_user.o Time.o -o sputify.out

main.o: main.cpp
	${CC} -c main.cpp 

request.o: utils/request.cpp utils/request.hpp
	${CC} -c utils/request.cpp

response.o: utils/response.cpp utils/response.hpp
	${CC} -c utils/response.cpp

strutils.o: utils/strutils.cpp utils/strutils.hpp
	${CC} -c utils/strutils.cpp

template_parser.o: utils/template_parser.cpp utils/template_parser.hpp
	${CC} -c utils/template_parser.cpp

utilities.o: utils/utilities.cpp utils/utilities.hpp
	${CC} -c utils/utilities.cpp

route.o : server/route.cpp server/route.hpp
	${CC} -c server/route.cpp

server.o: server/server.cpp server/server.hpp
	${CC} -c server/server.cpp 

handlers.o: handlers.cpp handlers.hpp
	${CC} -c handlers.cpp

Spotify.o: Spotify.cpp Spotify.hpp
	${CC} -c Spotify.cpp  

User.o: User.cpp User.hpp
	${CC} -c User.cpp 

Artist.o: Artist.cpp Artist.hpp
	${CC} -c Artist.cpp

Regular_user.o: Regular_user.cpp Regular_user.hpp
	${CC} -c Regular_user.cpp

Music.o: Music.cpp Music.hpp
	${CC} -c Music.cpp	

Playlist.o: Playlist.cpp Playlist.hpp
	${CC} -c Playlist.cpp

string_functions.o: string_functions.cpp string_functions.hpp
	${CC} -c string_functions.cpp

Time.o: Time.cpp Time.hpp
	${CC} -c Time.cpp

clean:
	rm *.o
	rm ${EXE}