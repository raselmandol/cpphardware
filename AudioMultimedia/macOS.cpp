#include <iostream>
#include <AudioToolbox/AudioToolbox.h>

void playbackCallback(void* userData, AudioQueueRef queue, AudioQueueBufferRef buffer) {
}

int main() {
    AudioQueueRef queue;
    AudioStreamBasicDescription format;
    AudioQueueNewOutput(&format, playbackCallback, nullptr, nullptr, kCFRunLoopCommonModes, 0, &queue);
    AudioQueueStart(queue, nullptr);
    AudioQueueFlush(queue);
    AudioQueueStop(queue, true);
    AudioQueueDispose(queue, true);

    return 0;
}
