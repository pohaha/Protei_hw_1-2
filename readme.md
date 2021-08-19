# HW-1 - openssl library
## usage
* to create your own public key and a certificate - run the "create_certificate.sh" script it will create:
    * key.pem - which will contain your own uncrypted public key
    * cert.pem - your root's own self-signed sertificate
    * test_digest.txt - which will contain the fingerprint (digest) of your certificate - this will be used by my program for further validation

* run "configure.sh" to create a configuration of a project
* run "build.sh" to build the project
* run "run.sh" to run the built project

# TODO
* integrate hw#2 in this:\
make it so that one application sends output of a openssl parser element by element,\
second application reads the contents of a txt file and verifies them with read elements from parser one by one\
therefore - using shared memory for communication!