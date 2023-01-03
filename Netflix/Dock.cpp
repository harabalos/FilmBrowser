#include "Dock.h"
#include "graphics.h"
#include "config.h"
#include "FilmBrowser.h"

Dock::Dock()
    :Button{ x_pos = 500 , y_pos = -110,size_x = CANVAS_WIDTH / 2, size_y = CANVAS_WIDTH / 4, r_color = 1.0f, g_color = 1.0f, b_color = 1.0f }{}

Dock::~Dock()
{
}

void Dock::update()
{

    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasX(ms.cur_pos_y);

    GenreButton* cur_clearButton = nullptr;
    Slider* cur_SliderFrom = nullptr;
    Slider* cur_SliderTo = nullptr;
    SearchBar* cur_searchBar = nullptr;
    if (m_active)
    {
        setY(95);
        clearbutton->setY(60);
        sliderFrom->setY(150);
        sliderTo->setY(170);
        titleSearch->setY(137);
        actorSearch->setY(162);
        directorSearch->setY(187);
        //for (auto but : filmGenres)
        //{
        //    but->setY(60);
        //}
    }
    else
    {
        setY(-110);
        clearbutton->setY(-90);
        sliderFrom->setY(-90);
        sliderTo->setY(-90);
        titleSearch->setY(-90);
        actorSearch->setY(-90);
        directorSearch->setY(-90);

        //for (auto but : filmGenres)
        //{
        //    but->setY(-90);
        //}
    }

    if (clearbutton->contains(mx, my))
    {
        clearbutton->setHighlight(true);
        cur_clearButton = clearbutton;
    }
    else
    {
        clearbutton->setHighlight(false);
    }

    if (ms.button_left_pressed && cur_clearButton)
    {
        clearbutton->setActive(true);
    }
    else
    {
        clearbutton->setActive(false);
    }

    if (sliderFrom->contains(mx, my,10))
    {
        sliderFrom->setHighlight(true);
        cur_SliderFrom = sliderFrom;
    }
    else
    {
        sliderFrom->setHighlight(false);
    }

    if (sliderTo->contains(mx, my,10))
    {
        sliderTo->setHighlight(true);
        cur_SliderTo = sliderTo;
    }
    else
    {
        sliderTo->setHighlight(false);
    }

    if (ms.button_left_pressed && cur_SliderFrom)
    {
        sliderFrom->setActive(true);
        m_active_sliderFrom = sliderFrom;
    }
    else
    {
        sliderFrom->setActive(false);
    }

    if (ms.button_left_pressed && cur_SliderTo)
    {
        sliderTo->setActive(true);
        m_active_sliderTo = sliderTo;
    }
    else
    {
        sliderTo->setActive(false);
    }

    if (ms.dragging && m_active_sliderFrom)
    {
        m_active_sliderFrom->setX(mx);
        if (m_active_sliderFrom->getX() > 390) {
            m_active_sliderFrom->setX(390);
        }
        else if (m_active_sliderFrom->getX() < 300)
        {
            m_active_sliderFrom->setX(300);
        }

    }

    if (ms.button_left_released && m_active_sliderFrom)
    {

        m_active_sliderFrom->setActive(false);
        m_active_sliderFrom = nullptr;

    }

    if (ms.dragging && m_active_sliderTo)
    {
        m_active_sliderTo->setX(mx);
        if (m_active_sliderTo->getX() > 390) {
            m_active_sliderTo->setX(390);
        }
        else if (m_active_sliderTo->getX() < 300)
        {
            m_active_sliderTo->setX(300);
        }
    }

    if (ms.button_left_released && cur_SliderTo)
    {
        m_active_sliderTo->setActive(false);
        m_active_sliderTo = nullptr;

    }

    if (clearbutton->getActive())
    {
        sliderFrom->setX(300);
        sliderTo->setX(390);
    }

    for (auto sb : searchbars)
    {
        if (sb->contains(mx, my))
        {
            sb->setHighlight(true);
            cur_searchBar = sb;
        }
        else
        {
            sb->setHighlight(false);
        }
    }


    if (ms.button_left_pressed && cur_searchBar)
    {
        m_active_searchBar = cur_searchBar;
        m_active_searchBar->setActive(true);
        for (auto sb : searchbars)
        {
            if (sb != m_active_searchBar)
            {
                sb->setActive(false);
            }
        }
    }









}

void Dock::draw()
{
    graphics::Brush br;

    br.fill_color[0] = r_color;
    br.fill_color[1] = g_color;
    br.fill_color[2] = b_color;
    br.outline_opacity = 0.0f;
    br.fill_opacity = 1.0f;
    br.texture = ASSET_PATH"dock.png";
    graphics::drawRect(x_pos, y_pos, size_x, size_y, br);

    graphics::Brush br1;

    br1.fill_color[0] = 0.6f;
    br1.fill_color[1] = 0.6f;
    br1.fill_color[2] = 0.6f;
    br1.outline_opacity = 0.0f;
    br1.fill_opacity = 1.0f;
    graphics::drawRect(x_pos, y_pos - 80, size_x - 5, CANVAS_HEIGHT / 16, br1);

    br1.fill_color[0] = 1.0f;
    br1.fill_color[1] = 1.0f;
    br1.fill_color[2] = 1.0f;
    graphics::setFont(ASSET_PATH"OpenSans-Regular.ttf");
    graphics::drawText(x_pos-20, y_pos-70, 20, "Filters", br1);
    graphics::drawText(x_pos - 200, y_pos - 45, 15, "Genres:", br1);
    graphics::drawText(x_pos - 235, y_pos + 40, 10, "Year:", br1);
    graphics::drawText(x_pos - 235, y_pos + 57, 10, "From:", br1);
    graphics::drawText(x_pos - 235, y_pos + 77, 10, "To:", br1);
    //br1.outline_opacity = 1.0f;
    //br1.fill_color[0] = 0.7f;
    //br1.fill_color[1] = 0.7f;
    //br1.fill_color[2] = 0.7f;
    //br1.fill_opacity = 0.7f;
    graphics::drawText(x_pos , y_pos +20 , 15, "Filter by:", br1);
    graphics::drawText(x_pos , y_pos +45 , 15, "Title:", br1);
    titleSearch->draw();
    graphics::drawText(x_pos -10, y_pos +70 , 15, "Actor:", br1);
    actorSearch->draw();
    graphics::drawText(x_pos -25, y_pos +95 , 15, "Director:", br1);
    directorSearch->draw();


    clearbutton->draw();
    sliderFrom->draw();
    sliderTo->draw();
    for (auto sb : searchbars)
    {
        sb->update();
    }

    //for (auto but : filmGenres)
    //{
    //    but->draw();
    //}


}
