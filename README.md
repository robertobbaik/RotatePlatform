# RotatePlatform

- Complex Platform 은 AddActorLocalOffset을 통해 Y축 움직임을 수행합니다.

- 방향 및 속도 변환을 주기위해 Sin함수를 통해 구현했습니다.

- 움직이는 속도 및 처음 이동할 방향을 리플렉션을 통해 에디터에서 설정할 수 있게 구현했습니다.


- Rotate Platform 은 회전하는 플랫폼이고, AddActorLocalRotation을 통해 움직임을 수행합니다.

- GetWorldTimerManager를 통해 회전하는 방향을 특정 주기마다 변경하도록 구현했습니다.

- Enum을 통해 Roll, Pitch, Yaw 회전으로 전환할 수 있도록 구현했습니다.

- 회전방향 주기, Enum, 회전 속도 등을 리플렉션을 통해 에디터에서 설정할 수 있게 구현했습니다.
