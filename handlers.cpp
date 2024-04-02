#include "handlers.hpp"
#include "Errors.hpp"

Response* FirstPage_Handler::callback(Request* req)
{

    if (spotify.find_loged_in_user() == NULL) 
    {
        Response* res = Response::redirect("/home");
        return res;
    }

    else if (spotify.find_loged_in_user()->is_user_artist())
    {
        Response* res = Response::redirect("/home_artist");
        res->setSessionId(spotify.find_loged_in_user()->get_username());
        return res;
    }

    else if (spotify.find_loged_in_user()->is_user_regular())
    {
        Response* res = Response::redirect("/home_user");
        res->setSessionId(spotify.find_loged_in_user()->get_username());
        return res;        
    }   

    Response* res = Response::redirect("/");
    return res;
}

Response* Signup_Handler::callback(Request* req) {
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string mode = req->getBodyParam("mode");
    
    try {
    spotify.add_user(username, password, mode);
    
    Response* res = Response::redirect("/");
    res->setSessionId(username);
    return res;
    
    } catch (...) {
        Response* res = Response::redirect("/signup_inc");
		return res;
    }
}

Response* Login_Handler::callback(Request* req)
{
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    try {
    spotify.login(username, password);
    Response* res = Response::redirect("/");
    res->setSessionId(username);
    return res;
    
    } 
    catch (...) {
        Response* res = Response::redirect("/login_inc");
		return res;
    }
}

Response* Logout_Handler::callback(Request* req)
{
    if (spotify.find_loged_in_user() != NULL) 
        spotify.find_loged_in_user()->log_out();

    Response* res = Response::redirect("/");
    return res;
}

Response* UsersInfo_Handler::callback(Request* req)
{
    if(spotify.find_loged_in_user() == NULL)
    {
        Response* res = Response::redirect("/");
        return res; 
    }

    Response* res = new Response;
    string html;
	string head;
	string body;

    head = "<head>";
	head += "<title>SPUTIFY</title>";
	head += "<meta charset=\"UTF-8\">";
	head += "<link rel=\"stylesheet\" href=\"static/common.css\">";
	head += "</head>";

    body = "<body>";
    body += "<a href=\"/logout\">LOG OUT</a>";
    
    for (int i = 1; i <= spotify.users_count(); i++) 
    {
        User* user = spotify.find_user_by_id(i);
        body += "<button onclick=\"document.location='/home'\">";
            
        body += "User ID: " + to_string(i) + "<br>";
        body += "Name: " + user->get_username() + "<br>";
        body += "Mode: " + user->get_mode() + "<br>";
        body += "</button><br>";
    }

    body += "</body>";
    html = "<!DOCTYPE html>";
    html += "<html lang=\"en\">" + head + body + "</html>";
	res->setBody(html);
	return res;
}

Response* AddMusic_Handler::callback(Request* req)
{
    try{
        string title = req->getBodyParam("title");
        string path = req->getBodyParam("path");
        string year = req->getBodyParam("year");
        string album = req->getBodyParam("album");
        string tags = req->getBodyParam("tags");
        string duration = req->getBodyParam("duration");

        spotify.add_music(title, path, year, album, tags, duration);
        Response* res = Response::redirect("/");
        return res;
    }
    catch(Permission_denied_ex& ex)
    {
        Response* res = Response::redirect("/");
		return res;       
    }
    
    catch(...)
    {
        Response* res = Response::redirect("/add_music_inc");
		return res;       
    }
}