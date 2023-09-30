import cv2
import numpy as np
from skimage.metrics import structural_similarity as ssim

def compress_video(input_path, output_path, compression_factor=0.5):
    cap = cv2.VideoCapture(input_path)
    fps = int(cap.get(cv2.CAP_PROP_FPS))
    frame_size = (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)))

    fourcc = cv2.VideoWriter_fourcc(*'H264')
    out = cv2.VideoWriter(output_path, fourcc, fps, frame_size)

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break

        # Simulate compression using resize and encode
        compressed_frame = cv2.resize(frame, (0, 0), fx=compression_factor, fy=compression_factor)
        _, encoded_frame = cv2.imencode('.jpg', compressed_frame)

        # Decode the frame back for writing
        decoded_frame = cv2.imdecode(encoded_frame, 1)
        out.write(decoded_frame)

    cap.release()
    out.release()

def calculate_psnr(original, compressed):
    mse = np.mean((original - compressed) ** 2)
    max_pixel = 255.0
    psnr = 20 * np.log10(max_pixel / np.sqrt(mse))
    return psnr

def calculate_ssim(original, compressed):
    gray_original = cv2.cvtColor(original, cv2.COLOR_BGR2GRAY)
    gray_compressed = cv2.cvtColor(compressed, cv2.COLOR_BGR2GRAY)
    index, _ = ssim(gray_original, gray_compressed, full=True)
    return index

# Example usage
input_video = 'input_video.mp4'
compressed_video = 'compressed_video.mp4'
output_video = 'output_video.mp4'

# Compression
compress_video(input_video, compressed_video, compression_factor=0.5)

# Decompression (for quality evaluation)
compress_video(compressed_video, output_video, compression_factor=2.0)

# Quality Evaluation
original_frame = cv2.imread(input_video)
compressed_frame = cv2.imread(output_video)

psnr_value = calculate_psnr(original_frame, compressed_frame)
ssim_index = calculate_ssim(original_frame, compressed_frame)

print(f'PSNR: {psnr_value} dB')
print(f'SSIM: {ssim_index}')
