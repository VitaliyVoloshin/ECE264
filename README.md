# [ECE26400: Advanced C Programming](https://github.com/astpierre/ECE264)
## Description
> Advanced C Programming ~ Fall 2018

## Git configuration for private repositories
1.	Change to your ECE264 directory: ```cd ~/ECE264```
2.	Remove prev config settings: ```git remote rm origin```
3.	Add origin: ```git remote add origin git@github.com:astpierre/ECE264.git```
4.	Generate new SSH key: ```ssh-keygen -t rsa -b 4096 -C "web@github.com"```
5.	Move key to proper folder: ```mv <keyname> ../.ssh```
6.	Also move public key: ```mv <keyname>.pub ../.ssh```
7.	Copy public key and add to Github repo: ```cat ~/.ssh/<keyname>.pub```
8.	Add key at SSH agent level: ```eval "$(ssh-agent -s)"```
9.	Add key at SSH agent level: ```ssh-add ~/.ssh/<keyname>```

## Notes:
* pull problems from [course repo](https://github.com/PurdueECE264/2018FallProblems) 
* zip submittable files using ```zip target.zip target.c```
