const points = (games: string[]): number => {
  let our_team = 0;
  games.forEach((item) => {
    our_team =
      Number(item.split(":")[0]) > Number(item.split(":")[1])
        ? our_team + 3
        : Number(item.split(":")[0]) < Number(item.split(":")[1])
        ? our_team + 0
        : our_team + 1;
  });
  return our_team;
};
