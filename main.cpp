#include <iostream>
#include <string>
#include "server/server.hpp"
#include "Spotify.hpp"
#include "handlers.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    try 
    {
        Server server(argc > 1 ? atoi(argv[1]) : 5000);
        Spotify spotify;

        server.get("/common.css", new ShowPage("static/common.css"));
        server.get("/Tab.css", new ShowPage("static/Tab.css"));

        server.get("/", new FirstPage_Handler(spotify));
        server.get("/home", new ShowPage("static/home.html"));
        server.get("/home_artist", new ShowPage("static/home_artist.html"));
        server.get("/home_user", new ShowPage("static/home_user.html"));

        server.get("/signup", new ShowPage("static/signup/signup.html"));
        server.get("/signup_inc", new ShowPage("static/signup/signup_inc.html"));
        server.post("/signup", new Signup_Handler(spotify));

        server.get("/login", new ShowPage("static/login/login.html"));
        server.get("/login_inc", new ShowPage("static/login/login_inc.html"));
        server.post("/login", new Login_Handler(spotify));
        server.get("/logout", new Logout_Handler(spotify));   

        server.get("/users_info", new UsersInfo_Handler(spotify));

        server.get("/add_music", new ShowPage("static/add_music.html"));
        server.get("/add_music_inc", new ShowPage("static/signup/add_music_inc.html"));
        server.post("/add_music", new AddMusic_Handler(spotify));


        server.setNotFoundErrPage("static/404.html");
        server.run();
    } 
    catch (Server::Exception e) 
    {
        cerr << e.getMessage() << endl;
    }
}
