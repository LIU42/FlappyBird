#ifndef __WIDGETS_WELCOME_H__
#define __WIDGETS_WELCOME_H__

#include <QWidget>
#include <QPushButton>

#include "Models/FlappyBird.h"
#include "Resources/GameImages.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class WelcomeWidget;
}

QT_END_NAMESPACE

class WelcomeWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::WelcomeWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        WelcomeWidget(QWidget* parent = nullptr);
        ~WelcomeWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();

    public:
        QPushButton* getStartButton();
};
#endif