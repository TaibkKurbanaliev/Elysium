#pragma once
#include "Elysium/Core.h"

namespace Elysium
{
	class ELYSIUM_API Widget
	{
	public:
		Widget() : ID(s_CurrentID) { s_CurrentID++; }
	protected:
		int ID;
	private:
		unsigned int s_CurrentID = 0;
	};
}