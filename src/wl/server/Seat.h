#ifndef WL_SERVER_SEAT_H
#define WL_SERVER_SEAT_H

#include "Resource.h"
#include "Type.h"

#include <wayland-server-protocol.h>

#include <memory>

namespace wl {
namespace server {

class Seat : public BASE_TYPE(wl_seat)
{
    friend class Type;

public:
    Seat(wl_client *client, uint32_t id);

private:
    void getPointer(struct wl_client *client, uint32_t id);
    void getKeyboard(struct wl_client *client, uint32_t id);
    void getTouch(struct wl_client *client, uint32_t id);
    void release(struct wl_client *client);

private:
    std::shared_ptr<Resource> resource_;
};

} // namespace server
} // namespace wl

#endif // !WL_SERVER_SEAT_H