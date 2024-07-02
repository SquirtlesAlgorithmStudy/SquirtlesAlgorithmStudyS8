//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 2024/07/02.
//

// 1. 개강총회 시작 전+ 시작하자마자 '대화'한 적 있는 닉네임 체크
// 2. 개강총회 끝 + 스트리밍 끝날 때까지 '대화' 한 적 있는 닉네임 체크
// 3. 스트리밍 끝나고 대화한 닉네임은 다음 스트리밍 기록으로 간주
// 4. 대기시간은 00:00 부터

// 시작출석을 안하고 퇴장출석만 하는 사람도 있다는 것을 간과

import Foundation

let times = readLine()!
let splitedtimes = times.components(separatedBy: " ")
let openMeetStartTime = splitedtimes[0]
let openMeetEndTime = splitedtimes[1]
let streamingEndTime = splitedtimes[2]

var lastChatTime = "00:00"
var openAttendees: Set<String> = []
var endAttendees: Set<String> = []

repeat {
    if let chat = readLine() {
        if chat.isEmpty { break }
        let splitedChat = chat.components(separatedBy: " ")
        let chatTime = splitedChat[0]
        let studentName = splitedChat[1]

        if chatTime <= openMeetStartTime {
            openAttendees.insert(studentName)
        } else if chatTime >= openMeetEndTime && chatTime <= streamingEndTime {
            endAttendees.insert(studentName)
        }
        lastChatTime = chatTime
    } else { break }

} while streamingEndTime >= lastChatTime

print(Array(openAttendees.intersection(endAttendees)).count)
