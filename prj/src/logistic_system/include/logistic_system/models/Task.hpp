/*
 * Task.hpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#ifndef MODELS_TASK_HPP_
#define MODELS_TASK_HPP_

class Task
{
	public:
		Task(int startStorage, int destinationStorage, int prefferedRobot = -1)
				: m_startStorageId(startStorage), m_destStorageId(destinationStorage),
					m_prefferedRobotId(prefferedRobot)
		{
		}

		int startStorageId() const
		{
			return m_startStorageId;
		}

		int desinationStorageId() const
		{
			return m_destStorageId;
		}

		int prefferedRobotId() const
		{
			return m_prefferedRobotId;
		}

	private:
		int m_startStorageId;
		int m_destStorageId;
		int m_prefferedRobotId;
}
;

#endif /* TASK_HPP_ */
