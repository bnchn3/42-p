SELECT last_name, first_name
	FROM user_card
	INNER JOIN member ON user_card.id_user = member.id_user_card
	WHERE last_name LIKE '%-%'
		OR first_name LIKE '%-%'
	ORDER BY last_name ASC, first_name ASC;
