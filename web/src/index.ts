const startBtn = document.getElementById('start') as HTMLButtonElement;
const video = document.getElementById('video') as HTMLVideoElement;
const canvas = document.getElementById('out') as HTMLCanvasElement;

startBtn!.onclick = async () => {
  const stream = await navigator.mediaDevices.getUserMedia({ video: true });
  video.srcObject = stream;
  await video.play();

  const off = new OffscreenCanvas(video.videoWidth || 640, video.videoHeight || 480);
  const ctx = off.getContext('2d')!;
  const worker = new Worker('worker.js');

  worker.onmessage = (e) => {
    const bitmap = e.data as ImageBitmap;
    canvas.width = bitmap.width;
    canvas.height = bitmap.height;
    const c2 = canvas.getContext('2d')!;
    c2.drawImage(bitmap, 0, 0);
  };

  const loop = () => {
    ctx.drawImage(video, 0, 0);
    off.convertToBlob().then(blob => {
      createImageBitmap(blob).then(bitmap => {
        worker.postMessage({ bitmap }, [bitmap]);
      });
    });
    requestAnimationFrame(loop);
  };
  loop();
};
