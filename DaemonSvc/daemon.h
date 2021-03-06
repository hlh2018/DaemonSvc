#pragma once
#include <Windows.h>
#include "scoped_handle.h"
#include "singleton.h"
#include "tdef.h"


class CDaemon : public Singleton<CDaemon>
{
    friend class Singleton<CDaemon>;

private:
    CDaemon(void);

public:
    ~CDaemon(void);

public:
    bool start();
    void keep_running();
    void stop();
    void restart();

private:
    bool start_tasks_by_config(const tstring& config_file);

private:
    scoped_handle<> m_exit_event;
};
