#include "support.h"

Support::Support(QObject *parent, std::unique_ptr<QObject> it, std::unique_ptr<Game> git): QObject{parent}, _it{std::move(it)}, _git{std::move(git)}
{
    QObject::connect(this->_git.get(), SIGNAL(randomized()), this, SLOT(invokeQml()));
}

void Support::invokeQml()
{
    QMetaObject::invokeMethod(this->_it.get(), "cordinates",
            Q_ARG(int, this->_git.get()->getX()),
            Q_ARG(int, this->_git.get()->getY())
                              );
}

Support::~Support()
{

}
