pipeline {
    agent any
    environment
    {

    }
    stages {
        stage('Create Docker Image') {
            steps {
                sh '''cp /home/ubuntu/module/parasoft_cpptest_2020.2.0_linux_x86_64.tar.gz ./
                cp /home/ubuntu/module/license.properties ./
                docker build -t webinar-demo-ja:webinar-demo-ja .'''
            }
        }
        stage('Run Docker Container') {
            steps {
                sh 'docker run --net host --name cpptest-workflow-demo --workdir /home/cpptest -v /home/ubuntu/cpptest_workflow:/home/cpptest/cpptest_workflow -itd webinar-demo-ja:webinar-demo-ja'
            }
        }
        stage('Build Project') {
            steps {
                sh 'docker exec --user 1000 -i cpptest-workflow-demo /bin/bash -c "cd webinar-demo-ja/FlowAnalysis && cmake . && cpptesttrace --cpptesttraceProjectName=FlowAnalysis make"'
            }
        }
        stage('Create C++test Project') {
            steps {
                sh 'docker exec --user 1000 -i cpptest-workflow-demo cpptestcli -data . -bdf webinar-demo-ja/FlowAnalysis/cpptestscan.bdf -localsettings webinar-demo-ja/cpptest.ls.properties -showdetails'
            }
        }
        stage('Run Tests') {
            parallel {
                stage('Run MISRA Guideline Test') {
                    steps {
                        sh 'echo "Run MISRA Guideline Test"'
                        //sh 'cpptestcli -data webinar-demo-ja/ -resource FlowAnalysis -config "builtin://MISRA C 2012" -localsettings webinar-demo-ja/cpptest.ls.properties -showdetails -appconsole stdout'
                    }
                }
                stage('Run Security Test') {
                    steps {
                        sh 'echo "Run Security Test"'
                        //sh 'cpptestcli -data webinar-demo-ja/ -resource FlowAnalysis -config "builtin://CERT C Coding Standard" -localsettings webinar-demo-ja/cpptest.ls.properties -showdetails -appconsole stdout'
                    }
                }
                stage('Run Unit Tests') {
                    steps {
                        sh 'echo "Run Unit Tests"'
                        //cpptestcli -data webinar-demo-ja -resource FlowAnalysis -config "builtin://Run Unit Tests" -localsettings webinar-demo-ja/cpptest.ls.properties -showdetails -appconsole stdout
                    }
                }
            }
        }
        stage('Delete Docker Container') {
            steps {
                sh '''docker stop cpptest-workflow-demo
                docker rm cpptest-workflow-demo'''
            }
        }
        stage('Delete Docker Image') {
            steps {
                sh 'docker rmi webinar-demo-ja:webinar-demo-ja'
            }
        }
    }
    post {
        success {
            cleanWs()
        }
    }
}

