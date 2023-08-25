#ifndef __WIDGETS_PLAYING_H__
#define __WIDGETS_PLAYING_H__

#include <QWidget>

#include "../Models/flappybird.h"
#include "../Widgets/resource.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class PlayingWidget;
}

QT_END_NAMESPACE

class PlayingWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::PlayingWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        PlayingWidget(QWidget* parent = nullptr);
        ~PlayingWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
};
#endif