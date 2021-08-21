#! /bin/sh
cd certificate
openssl req -x509 -newkey rsa:2048 -days 3650 -nodes -keyout key.pem -out cert.pem

touch ../consumer/test_digest.txt
openssl x509 -noout -in cert.pem -fingerprint -sha256 > ../consumer/test_digest.txt
