#include "FilmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "Film.h"
#include "Button.h"

void FilmBrowser::update()
{

    initializeVectorFilms();
    allFilms[0]->update();
    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasX(ms.cur_pos_y);
    
}

void FilmBrowser::draw()
{
    //draw background
    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    br.fill_opacity = 0.2f;
    br.fill_secondary_color[0] = 0.8f;
    br.fill_secondary_color[1] = 0.8f;
    br.fill_secondary_color[2] = 0.8f;
    br.fill_secondary_opacity = 0.9f;
    br.gradient_dir_u = 0.0f;
    br.gradient_dir_v = 0.6f;
    br.outline_opacity = 0.0f;
    br.gradient = true;
    graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    //draw film
    initializeVectorFilms();
    allFilms[0]->draw();
   
    


    
}

void FilmBrowser::initializeVectorFilms()
{
    allFilms.push_back(new Film("Fight Club", "1999", "David Fincher", "Brad Pitt,Edward Norton",filmGenre , "An insomniac office worker and a devil-may-care soap maker form an underground fight club that evolves into much more."));
    //allFilms.push_back(new Film("Schindler's List", "1993", "Steven Spielberg", "Liam Neeson, Ralph Fiennes, Ben Kingsley", "drama,history", "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis."));
    //allFilms.push_back(new Film("The Godfather", "1972", "Francis Ford Coppola", "Al Pacino,James Caan,Marlon Brando", "Drama, history", "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son."));
    //allFilms.push_back(new Film("The Terminator", "1984", "James Cameron", "Arnold Schwarzeneger,Linda Hamilton,Michael Biehn", "SciFi,Action", "A human soldier is sent from 2029 to 1984 to stop an almost indestructible cyborg killing machine, sent from the same year, which has been programmed to execute a young woman whose unborn son is the key to humanity's future salvation."));
    //allFilms.push_back(new Film("Indian Jones and the Raiders of the Lost Ark", "1981", "Steven Spielberg", "Harrison Ford,Karen Allen,Paul Freeman", "Adventure,Action", "KrioraArchaeology professor Indiana Jones ventures to seize a biblical artef act known as the Ark of the Covenant.While doing so, he puts up a fight against Renee and a troop of Nazis."));
    //allFilms.push_back(new Film("Indiana Jones and the Temple of Doom", "1984", "Steven Spielberg", "HarrisonFord, Kate Capshaw, Ke Huy Quan", "Adventure,Action", "A skirmish in Shanghai puts archaeologist Indiana Jones, his partner Short Round and singer Willie Scott crossing paths with an Indian village desperate to reclaim a rock stolen by a secret cult beneath the catacombs of an ancient palace."));
   // allFilms.push_back(new Film("Pulp Fiction", "1994", "Quentin Tarantino", "John Travolta, SamuelL. Jackson, Uma Thurman", "Drama,Crime", "The lives of two rob hitmen, aboxer, a gangster and his wife, and apair of diner bandits inter twine in four tales of violence andredemption."));
   // allFilms.push_back(new Film("Star Wars:Episode IV- A New Hope", "1977", "George Lucas", "CarrieFisher, Harrison Ford, Mark Hamill", "Adventure,Action,Fantasy", "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a Wookiee and two droids to save the galaxy from the Empire's world-destroying battle station, while also attempting to rescue Princess Leia from the mysterious Darth Vader."));
   // allFilms.push_back(new Film("Star Wars:Episode V-The Empire Strikes Back", "1980", "Irvin Kershner", "Carrie Fisher, Harrison Ford, Mark Hamill", "Adventure,Action,Fantasy", "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader andbounty hunter BobaFett."));
}

void FilmBrowser::init()
{
}


FilmBrowser::FilmBrowser()
{
}

FilmBrowser::~FilmBrowser()
{
    if (allFilms[0]) {
        delete allFilms[0];
    }


}
