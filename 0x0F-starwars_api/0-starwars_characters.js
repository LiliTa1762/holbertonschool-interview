#!/usr/bin/node

const request = require('request');

const movieID = process.argv[2];

const url = `https://swapi-api.hbtn.io/api/films/${movieID}`;

request(url, (error, response, body) => {
  if (error) {
    console.log(error);
  }

  const characters = JSON.parse(body).characters;

  for (const char in characters) {
    const url2 = `https://swapi-api.hbtn.io/api/people/${char}/`;
    request(url2, (error, response, body) => {
      if (error) {
        console.log(error);
      }

      const names = JSON.parse(body).name;
      if (names !== undefined) {
        console.log(names);
      }
    });
  }
});
