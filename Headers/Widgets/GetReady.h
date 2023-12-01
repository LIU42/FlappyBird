#ifndef __WIDGETS_PREPARE_H__
#define __WIDGETS_PREPARE_H__

#include <QWidget>

#include "Models/FlappyBird.h"
#include "Resources/GameImages.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
class GetReadyWidget;
}

QT_END_NAMESPACE

class GetReadyWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::GetReadyWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        GetReadyWidget(QWidget* parent = nullptr);
        ~GetReadyWidget();

    public:
        void setGame(MainGame* pGame);
        void setImages(GameImages* pImages);
        void setBackground();
};
#endif