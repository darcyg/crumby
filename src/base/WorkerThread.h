/**
 * @file   WorkerThread.h
 * @Author icke2063
 * @date   31.05.2013
 * @brief  Brief description of file.
 *
 * Copyright © 2013 icke2063 <icke2063@gmail.com>
 *
 * This framework is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef WORKERTHREAD_H_
#define WORKERTHREAD_H_

#include <auto_ptr.h>


#include <MBThreadPool.h>
using namespace MB_Framework;

#include <Mutex.h>
#include <Logger.h>

#include <boost/thread.hpp>

using namespace std;

namespace MB_Gateway {

class WorkerThread: public MB_Framework::MBWorkerThread ,public Logger{
public:
	WorkerThread(deque<MBFunctor *> *functor_queue, Mutex *functor_lock);

	virtual ~WorkerThread();

	void startThread(void);
	void stopThread(void);

private:

	boost::thread* p_worker_thread;
	bool m_running;

	auto_ptr<MBFunctor>curFunctor;
	virtual void thread_function (void);
};

} /* namespace MB_Framework */
#endif /* WORKERTHREAD_H_ */
