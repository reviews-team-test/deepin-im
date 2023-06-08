#include "InputContext1.h"

#include "InputcontextAdaptor.h"
#include "dimcore/Events.h"

#include <QDBusConnection>

using namespace org::deepin::dim;

static const QString inputcontextPath = "/org/freedesktop/portal/inputcontext/%1";

InputContext1::InputContext1(Dim *dim, QObject *parent)
    : InputContext(dim, parent)
    , adaptor_(new InputcontextAdaptor(this))
    , path_(inputcontextPath.arg(id()))
{
    QDBusConnection::sessionBus().registerObject(path_, this);
}

InputContext1::~InputContext1() { }

void InputContext1::commitString(const QString &text) {
    emit adaptor_->CommitString(text);
}

void InputContext1::FocusIn()
{
    focusIn();
}

void InputContext1::FocusOut()
{
    focusOut();
}

void InputContext1::Destroy()
{
    deleteLater();
}

void InputContext1::ProcessKeyEvent(
    uint32_t keyval, uint32_t keycode, uint32_t state, bool isRelease, uint32_t time)
{
    KeyEvent e(this, keyval, keycode, state, isRelease, time);
    keyEvent(e);
}
