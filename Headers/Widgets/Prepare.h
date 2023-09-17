#ifndef __WIDGETS_PREPARE_H__
#define __WIDGETS_PREPARE_H__

#include <QWidget>

#include "Models/FlappyBird.h"
#include "Widgets/Resource.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class PrepareWidget;
}

QT_END_NAMESPACE

class PrepareWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::PrepareWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        PrepareWidget(QWidget* parent = nullptr);
        ~PrepareWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
};
#endif