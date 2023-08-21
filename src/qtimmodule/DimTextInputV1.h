// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef DIMINPUTTEXTV1_H
#define DIMINPUTTEXTV1_H

#include "wayland-dim-text-input-unstable-v1-client-protocol.h"
#include "wl/client/ConnectionBase.h"

#include <QObject>

namespace wl {
namespace client {
class ZwpDimTextInputV1;
} // namespace client
} // namespace wl

struct zwp_dim_text_input_v1;

class DimTextInputV1 : public QObject
{
    Q_OBJECT

public:
    DimTextInputV1(QObject *parent = nullptr);

    bool available() const { return available_; }

    void focusIn();
    void focusOut();

    void reset();

protected:
    // wayland listeners
    void modifiers_map(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1, struct wl_array *map);
    void preedit_string(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1,
                        const char *text,
                        int32_t cursor_begin,
                        int32_t cursor_end);
    void commit_string(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1, const char *text);
    void delete_surrounding_text(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1,
                                 uint32_t before_length,
                                 uint32_t after_length);
    void done(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1, uint32_t serial);
    void keysym(struct zwp_dim_text_input_v1 *zwp_dim_text_input_v1,
                uint32_t serial,
                uint32_t time,
                uint32_t sym,
                uint32_t state,
                uint32_t modifiers);

signals:
    void preedit(const QList<QString> &preedit);
    void commitString(const QString &text);
    void forwardKey(uint32_t keyValue, uint32_t state, bool type);

private:
    std::unique_ptr<wl::client::ConnectionBase> wl_;
    bool available_;
    std::shared_ptr<wl::client::ZwpDimTextInputV1> ti_;
    static const zwp_dim_text_input_v1_listener tiListener;

    QList<Qt::KeyboardModifier> modifiersMap_;
    Qt::KeyboardModifiers modifiersToQtModifiers(uint32_t modifiers);
};

#endif // !DIMINPUTTEXTV1_H