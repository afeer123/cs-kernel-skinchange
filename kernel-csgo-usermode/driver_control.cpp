#include "driver_control.hpp"

ULONG driver_control::get_client_base(ULONG process_id)
{
    INFO_STRUCT info = { 0 };
    info.code = CODE_CLIENT_REQUEST;
    info.process_id = process_id;

    hook::call_hook(&info);

    return info.client_base;
}

ULONG driver_control::get_engine_base(ULONG process_id)
{
    INFO_STRUCT info = { 0 };
    info.code = CODE_ENGINE_REQUEST;
    info.process_id = process_id;

    hook::call_hook(&info);

    return info.engine_base;
}