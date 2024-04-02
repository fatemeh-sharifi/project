#ifndef HANDLERS_HPP
#define HANDLERS_HPP
#include "server/server.hpp"
#include "Spotify.hpp"
#include <cstdlib>
#include <ctime>  
#include <iostream>

class My_Request_Handlers : public RequestHandler 
{
public:
    My_Request_Handlers(Spotify& sp) : spotify(sp) {}
    virtual Response* callback(Request *) = 0;
protected:
    Spotify& spotify;
};

class FirstPage_Handler : public My_Request_Handlers 
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);
};

class Signup_Handler : public My_Request_Handlers 
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);
};

class Login_Handler : public My_Request_Handlers
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);  
};

class Logout_Handler : public My_Request_Handlers
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);
};

class UsersInfo_Handler : public My_Request_Handlers
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);
};

class AddMusic_Handler : public My_Request_Handlers
{
public:
    using My_Request_Handlers::My_Request_Handlers;
    Response* callback(Request*);
};

#endif