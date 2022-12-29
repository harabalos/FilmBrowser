#include "FilmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "Film.h"
#include "Button.h"

bool startingFilm = true;
FilmBrowser* FilmBrowser::m_instance = nullptr;
void FilmBrowser::update()
{

    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasX(ms.cur_pos_y);

    Film* cur_film = nullptr;
    for (auto film : allFilms)
    {
        if (film->contains(mx, my))
        {
            film->setHighlight(true);
            cur_film = film;
        }
        else
        {
            film->setHighlight(false);
        }     

    }

    if (ms.button_left_pressed && cur_film)
    {
        m_active_film = cur_film;
        m_active_film->setActive(true);
        for (auto film : allFilms)
        {
            if (film != m_active_film)
            {
                film->setActive(false);

            }
        }

    }
    
    for (auto film : allFilms)
    {
        if (film->m_active_button == Drama)
        {
            state = DRAMA;
        }
        else if (film->m_active_button == History)
        {
            state = HISTORY;
        }
        else if (film->m_active_button == Crime)
        {
            state = CRIME;
        }
        else if (film->m_active_button == Action)
        {
            state = ACTION;
        }
        else if (film->m_active_button == Adventure)
        {
            state = ADVENTURE;
        }
        else if (film->m_active_button == Fantasy)
        {
            state = FANTASY;
        }
        else if (film->m_active_button == SciFi)
        {
            state = SCIFI;
        }

    }
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
    if (state == START)
    {
        for (size_t i = 0; i < allFilms.size(); i++)
        {
            allFilms[i]->draw();
        }

        if (startingFilm)
        {

            m_active_film = allFilms[0];
            m_active_film->setActive(true);
            startingFilm = false;
        }

        for (size_t i = 0; i < allFilms.size(); i++)
        {
            if (allFilms[i] == m_active_film)
            {
                allFilms[i]->update();
            }
        }
    }

    switch (state)
    {
    case DRAMA:


        for (size_t i = 0; i < dramaFilms.size(); i++)
        {
            dramaFilms[i]->draw();
        }
        for (size_t i = 0; i < dramaFilms.size(); i++)
        {
            if (dramaFilms[i] == m_active_film)
            {
                dramaFilms[i]->update();
            }
        }

        break;
    case HISTORY:

        for (size_t i = 0; i < historyFilms.size(); i++)
        {
            historyFilms[i]->draw();
        }
        for (size_t i = 0; i < historyFilms.size(); i++)
        {
            if (historyFilms[i] == m_active_film)
            {
                historyFilms[i]->update();
            }
        }
        break;
    case SCIFI:
        for (size_t i = 0; i < scifiFilms.size(); i++)
        {
            scifiFilms[i]->draw();
        }
        for (size_t i = 0; i < scifiFilms.size(); i++)
        {
            if (scifiFilms[i] == m_active_film)
            {
                scifiFilms[i]->update();
            }
        }

        break;
    case ACTION:
        for (size_t i = 0; i < actionFilms.size(); i++)
        {
            actionFilms[i]->draw();
        }
        for (size_t i = 0; i < actionFilms.size(); i++)
        {
            if (actionFilms[i] == m_active_film)
            {
                actionFilms[i]->update();
            }
        }
        break;
    case CRIME:
        for (size_t i = 0; i < crimeFilms.size(); i++)
        {
            crimeFilms[i]->draw();
        }
        for (size_t i = 0; i < crimeFilms.size(); i++)
        {
            if (crimeFilms[i] == m_active_film)
            {
                crimeFilms[i]->update();
            }
        }
        break;
    case FANTASY:
        for (size_t i = 0; i < fantasyFilms.size(); i++)
        {
            fantasyFilms[i]->draw();
        }
        for (size_t i = 0; i < fantasyFilms.size(); i++)
        {
            if (fantasyFilms[i] == m_active_film)
            {
                fantasyFilms[i]->update();
            }
        }
        break;
    case ADVENTURE:
        for (size_t i = 0; i < adventureFilms.size(); i++)
        {
            adventureFilms[i]->draw();
        }
        for (size_t i = 0; i < adventureFilms.size(); i++)
        {
            if (adventureFilms[i] == m_active_film)
            {
                adventureFilms[i]->update();
            }
        }
        break;
    default:
        break;
    }
}


void FilmBrowser::init()
{

    allFilms.push_back(new Film("Fight Club", "1999", "David Fincher", "Brad Pitt,Edward Norton", { Drama,Action}, "An insomniac office worker and a devil-may-care soap maker form an underground fight club that evolves into much more.",0));
    allFilms.push_back(new Film("Schindler's List", "1993", "Steven Spielberg", "Liam Neeson, Ralph Fiennes, Ben Kingsley", { Drama,History }, "In German - occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.",1));
    allFilms.push_back(new Film("The Godfather", "1972", "Francis Ford Coppola", "Al Pacino,James Caan,Marlon Brando", { Drama,History }, "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son.",2));
    allFilms.push_back(new Film("The Terminator", "1984", "James Cameron", "Arnold Schwarzeneger,Linda Hamilton,Michael Biehn", { SciFi,Action }, "A human soldier is sent from 2029 to 1984 to stop an almost indestructible cyborg killing machine, sent from the same year, which has been programmed to execute a young woman whose unborn son is the key to humanity's future salvation.",3));
    allFilms.push_back(new Film("Indian Jones and the Raiders of the Lost Ark", "1981", "Steven Spielberg", "Harrison Ford,Karen Allen,Paul Freeman", { Action,Adventure }, "KrioraArchaeology professor Indiana Jones ventures to seize a biblical artef act known as the Ark of the Covenant.While doing so, he puts up a fight against Renee and a troop of Nazis.",4));
    allFilms.push_back(new Film("Indiana Jones and the Temple of Doom", "1984", "Steven Spielberg", "HarrisonFord, Kate Capshaw, Ke Huy Quan", { Action,Adventure }, "A skirmish in Shanghai puts archaeologist Indiana Jones, his partner Short Round and singer Willie Scott crossing paths with an Indian village desperate to reclaim a rock stolen by a secret cult beneath the catacombs of an ancient palace.",5));
    allFilms.push_back(new Film("Pulp Fiction", "1994", "Quentin Tarantino", "John Travolta, SamuelL. Jackson, Uma Thurman", { Drama,Crime }, "The lives of two rob hitmen, aboxer, a gangster and his wife, and apair of diner bandits inter twine in four tales of violence andredemption.",6));
    allFilms.push_back(new Film("Star Wars:Episode IV- A New Hope", "1977", "George Lucas", "CarrieFisher, Harrison Ford, Mark Hamill", { Action,Fantasy, Adventure }, "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a Wookiee and two droids to save the galaxy from the Empire's world-destroying battle station, while also attempting to rescue Princess Leia from the mysterious Darth Vader.",7));
    allFilms.push_back(new Film("Star Wars:Episode V-The Empire Strikes Back", "1980", "Irvin Kershner", "Carrie Fisher, Harrison Ford, Mark Hamill", { Action,Fantasy, Adventure }, "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader andbounty hunter BobaFett.",8));

    for (size_t i = 0; i < allFilms.size(); i++)
    {
        for (size_t j = 0; j < allFilms[i]->getFilmGenre().size(); j++)
        {
            if (allFilms[i]->getFilmGenre()[j]->getKind() == "Drama")
            {
                dramaFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "History")
            {
                historyFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "Action")
            {
                actionFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "Adventure")
            {
                adventureFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "Crime")
            {
                crimeFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "Fantasy")
            {
                fantasyFilms.push_back(allFilms[i]);
            }
            else if (allFilms[i]->getFilmGenre()[j]->getKind() == "SciFI")
            {
                scifiFilms.push_back(allFilms[i]);
            }
        }
    }


    for (size_t i = 0; i < allFilms.size(); i++)
    {
        allFilms[i]->setX(86 + (i * 104));
        allFilms[i]->setY(100);
    }


}

FilmBrowser* FilmBrowser::getInstance()
{
    if (!m_instance)
    {
        m_instance = new FilmBrowser();
    }
    return m_instance;
}

FilmBrowser::~FilmBrowser()
{
    for (auto film : allFilms)
    {
        delete film;
        for (auto button : film->getFilmGenre())
        {
            delete button;
        }
    }
    allFilms.clear();
}