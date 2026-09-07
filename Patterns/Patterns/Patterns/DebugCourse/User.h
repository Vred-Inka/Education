#pragma once
#include <string>
#include <vector>

inline int g_Sum{};

struct Adress
{
	std::string street;
	std::string city;
	int zip{};
};

struct Profile
{
	std::string email;
	Adress adress;
};

class User
{
public:
	User(std::string name, Profile profile, std::vector<int> scores)
		:m_Name{ std::move(name) },
		m_Profile{ std::move(profile) },
		m_Scores{ std::move(scores) }
	{
	}

	const std::string GetName() const 
	{
		return m_Name;
	}

	const Profile& GetProfile() const
	{
		return m_Profile;
	}

	void Update(int value)
	{
		for (size_t i = 0; i < m_Scores.size(); ++i)
		{
			m_Scores[i] += value;
		}
	}

	int Compute(int weight)
	{
		int sum = 0;
		g_Sum = 0;
		for (size_t i = 0; i < m_Scores.size(); ++i)
		{
			g_Sum += m_Scores[i];
			sum += m_Scores[i] * weight;
		}

		return sum;
	}	

private:
	std::string m_Name{};
	Profile m_Profile{};
	std::vector<int> m_Scores;


};



