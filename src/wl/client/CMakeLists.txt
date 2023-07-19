set(WLC_SOURCES
  Connection.h
  Connection.cc
  Seat.h
  Seat.cc
  ZwpInputMethodManagerV2.h
  ZwpInputMethodManagerV2.cc
  ZwpInputMethodV2.h
  ZwpInputMethodV2.cc
  ZwpInputMethodKeyboardGrabV2.h
  ZwpInputMethodKeyboardGrabV2.cc
  ZwpVirtualKeyboardManagerV1.h
  ZwpVirtualKeyboardManagerV1.cc
  ZwpVirtualKeyboardV1.h
  ZwpVirtualKeyboardV1.cc
)

add_library(wlc STATIC
  ${WLC_SOURCES}
)

target_link_libraries(wlc PRIVATE
  Qt5::Core
  PkgConfig::wayland-client
  wayland_protocols
)