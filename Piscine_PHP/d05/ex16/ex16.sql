SELECT COUNT(id_film) AS 'movies'
	FROM member_history
	WHERE DATE(`date`) BETWEEN '2006-10-30' AND '2007-07-27'
UNION
SELECT COUNT(id_film)
	FROM member_history
	WHERE MONTH(`date`) = 12
		AND DAY(`date`) = 24;
